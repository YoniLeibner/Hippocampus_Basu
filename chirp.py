# from neuron import h,gui
import numpy as np
import matplotlib.pyplot as plt
import math
import sys,os, glob
from neo import io
import pandas as pd
import statsmodels.api as sm
from scipy.fft import fft, fftfreq,fftshift

################################################################################################
#
#open one by one
#enter = bad trace
# space = ok
#
################################################################################################
cells = dict(
    CA1_1=dict(name='044'),
    CA1_2=dict(name='062'),
    CA1_3=dict(name='084'),
    CA1_5=dict(name='101'),
             )



def eiline_resonance(I, V, fs=10000, max_Hz=30, smothed_factor=23, crop_fft_start=1000, norm=False, cut_start=2):

    lowess = sm.nonparametric.lowess
    Fs=1/fs

    f1 =np.abs(fft(V[crop_fft_start:]))
    L = f1.shape[0]
    f1*= 2.0/L
    f2 = 2.0/L *np.abs(fft(I[crop_fft_start:]))
    xf = fftfreq(L, Fs)[:L//2]
    y =(f1[:int(f1.shape[0]/2)]/f2[:int(f2.shape[0]/2)])
    y=y[cut_start:]
    xf=xf[cut_start:]
    print('cutting from freq:',xf[cut_start])
    y=y[xf<max_Hz]
    xf=xf[xf<max_Hz]
    y2 = lowess(y, xf, frac=1.0 / smothed_factor, return_sorted=False)

    if norm:
        y2/=y2.max()
        y/=y.max()
    return xf, y2

def generate_chirp_signal(t, f_start, f_end, amplitude=1.0):
    """
    Generates a linear chirp signal.

    Parameters:
    - duration (float): Total time of the signal in seconds.
    - sampling_rate (float): Sampling rate in Hz.
    - f_start (float): Starting frequency in Hz.
    - f_end (float): Ending frequency in Hz.
    - amplitude (float): Amplitude of the signal.

    Returns:
    - t (numpy.ndarray): Time vector.
    - signal (numpy.ndarray): Chirp signal.
    """
    # t = np.linspace(0, duration, int(sampling_rate * duration), endpoint=False)
    duration = t[-1]-t[0]
    c = (f_end - f_start) / duration  # Chirp rate
    phase = 2 * np.pi * (0.5 * c * t**2 + f_start * t)
    signal = amplitude * np.sin(phase)
    return signal

def get_delayed_chirp(t, f_start, f_end, amplitude=1.0, start_time=0, end_time=None):
    if end_time is None:
        end_time=t[-1]
    assert start_time <= end_time
    assert start_time >= 0
    assert end_time <= t[-1]
    t2 = t[np.logical_and(start_time <= t, t <= end_time)]
    t2-=t2[0]
    signal = generate_chirp_signal(t2, f_start, f_end, amplitude)
    dt = t[1]-t[0]
    full_signal = np.concatenate([np.zeros(int((start_time-t[0])/dt)), signal, np.zeros(int((t[-1]-end_time)/dt))])
    return full_signal


base_dirr = '/ems/elsc-labs/segev-i/yoni.leibner/PycharmProjects/Hippocampus_Basu/traces/210921_tanvi/'
plot_dirr = '/ems/elsc-labs/segev-i/yoni.leibner/PycharmProjects/Hippocampus_Basu/plot_chirp/210921_tanvi/'
fig_chirp, ax_chirp = plt.subplots(1, 1)
f_end = 30
start_time=1000/2
end_time = 31000/2
os.makedirs(plot_dirr, exist_ok=True)
for cell_name in cells.keys():
    fig, ax = plt.subplots(2, 1, sharex=True, figsize=(10, 3))
    f = os.path.join(base_dirr, "TB_210921_h_0" + cells[cell_name]['name'] + ".abf")
    r = io.AxonIO(f)
    bl = r.read_block(lazy=False)
    V = []
    for i in range(len(bl.segments)):
        V_temp = bl.segments[i].analogsignals[0][:, 0]
        V.append(np.array(V_temp) - np.array(V_temp)[0])
        sr = float(V_temp.sampling_rate)

    Vs = np.stack(V).mean(axis=0)[:, 0]
    T = np.arange(0, len(Vs), 1) * 1000.0 / sr
    # I = generate_chirp_signal(T/1000.0, f_start=0, f_end=f_end, amplitude=1.0)
    I = get_delayed_chirp(T/1000.0, f_start=0, f_end=f_end, amplitude=1.0, start_time=start_time/1000.0, end_time = end_time/1000.0)
    ax[0].plot(T, I, color='k')
    for j in range(len(V)):
        ax[1].plot(T, V[j][:, 0], label=str(j))
    ax[1].plot(T, Vs, color='k', ls='--', label='mean')
    ax[1].legend(loc=7)
    ax[1].axvline(start_time)
    ax[1].axvline(end_time)
    ax[0].set_ylabel('current (% signal)')
    ax[1].set_ylabel('Voltage (mV)')
    ax[1].set_xlabel('tome (ms)')

    fig.savefig(plot_dirr + cell_name + '.png')
    fig.savefig(plot_dirr + cell_name + '.pdf')
    # plt.close()
    print(sr)
    idx = np.logical_and(T<=end_time, T>=start_time)
    xf, y2 = eiline_resonance(I[idx], Vs[idx], fs=sr, max_Hz=min(30, f_end), smothed_factor=11, crop_fft_start=0, norm=True, cut_start=4)
    ax_chirp.plot(xf, y2, label=cell_name)
ax_chirp.legend()
ax_chirp.set_ylabel('power (%)')
ax_chirp.set_xlabel('f (Hz)')

fig_chirp.savefig(plot_dirr  + 'chirp_all.png')
fig_chirp.savefig(plot_dirr  + 'chirp_all.pdf')