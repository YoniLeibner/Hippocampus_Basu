# from neuron import h,gui
import numpy as np
import matplotlib.pyplot as plt
import math
import sys,os,glob
from neo import io
import pandas as pd

################################################################################################
#
#open one by one
#enter = bad trace
# space = ok
#
################################################################################################
cells = dict(CA1_1=dict(proximal=[8700, 8900], distal=[300, 550], basal=[4500, 4700], name='029'),
             CA1_2=dict(proximal=[8700, 8900], distal=[300, 550], basal=[4500, 4700], name='051'),
             CA1_3=dict(proximal=[8700, 8900], distal=[300, 550], basal=[4500, 4700], name='070'),
             CA1_4=dict(proximal=[8700, 8900], distal=[300, 550], basal=[4500, 4700], name='090'),
             CA1_5=dict(proximal=[8700, 8900], distal=[300, 550], basal=[4500, 4700], name='108'))

# plt.xlim(300, 550)
# plt.xlim(4500, 4750)
# plt.xlim(8700, 8900)

base_dirr = '/ems/elsc-labs/segev-i/yoni.leibner/PycharmProjects/Hippocampus_Basu/traces/210921_tanvi/'

plot_dirr = '/ems/elsc-labs/segev-i/yoni.leibner/PycharmProjects/Hippocampus_Basu/plot_traces/210921_tanvi/'
os.makedirs(plot_dirr, exist_ok=True)
# time_lims = [4500, 4750]
for cell_name in cells.keys():
    fig, ax = plt.subplots(3, 1, sharex=True)
    f = os.path.join(base_dirr, "TB_210921_h_0" + cells[cell_name]['name'] + ".abf")
    r = io.AxonIO(f)
    bl = r.read_block(lazy=False)
    for i_ax, loc in  enumerate(['basal', 'proximal', 'distal']):
       
        print(loc, cells[cell_name][loc])
        T0 = 0
        for i in range(len(bl.segments)):
            idx = 0
            V = bl.segments[i].analogsignals[idx][:, 0]
            V_np = np.array(V)
            sr = float(V.sampling_rate)
            T = T0 + np.arange(0, len(V_np), 1) * 1000.0 / sr
            V_np = V_np[np.logical_and(T>= cells[cell_name][loc][0], T<= cells[cell_name][loc][1])]
            T = T[np.logical_and(T >= cells[cell_name][loc][0], T <= cells[cell_name][loc][1])]
            T-=T[0]
            ax[i_ax].plot(T, V_np)
            ax[i_ax].set_ylabel('Voltage (mV)')
            ax[i_ax].set_title(loc)
            print(sr)
        ax[i_ax].set_ylim(-85, -40)
    ax[2].set_xlabel('time (ms)')
    plt.savefig(plot_dirr + cell_name + '.png')
    plt.savefig(plot_dirr + cell_name + '.pdf')
    plt.close()
#   np_traces = np_traces.flatten().reshape(np_traces.shape[:2])


    #   ax[0,0].plot(np_traces.T)
    #   ax[0,0].set_title('all traces '+str(len(np_traces)))
    #   ax[0,0].set_xlabel('time (ms)')
    #   ax[0,0].set_ylabel('Voltage (mV)')
    #
    #   # plt.savefig(plots_dir+'raw_'+inp_str+'.png')
    #   # plt.figure()
    #   ax[0,1].plot(np_traces_norm.T)
    #   ax[0, 1].set_title('all traces normalized')
    #   ax[0, 1].set_xlabel('time (ms)')
    #   ax[0, 1].set_ylabel('Voltage (mV)')
    #   # plt.savefig(plots_dir+'norm_'+inp_str+'.png')
    #   # plt.figure()
    #   ax[1,1].plot(T,avg_trace)
    #   ax[1, 1].set_title('avrage on all traces')
    #   ax[1, 1].set_xlabel('time (ms)')
    #   ax[1, 1].set_ylabel('Voltage (mV)')
    #   # plt.savefig(plots_dir+'avg_'+inp_str+'.png')
    #   # plt.figure()
    #   ax[1,0].plot(T,avg_inp)
    #   ax[1,0].set_title('curent injection')
    #   ax[1,0].set_xlabel('time (ms)')
    #   ax[1,0].set_ylabel('I (pA)')
    #   fig.savefig(plots_dir+'stim_cur_inj='+inp_str+'_new.png')
