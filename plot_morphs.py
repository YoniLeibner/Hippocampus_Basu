import os
from Neuron_analysis_tool.Analyzer import Analyzer
from glob import glob
from utils import morph_path
from matplotlib import pyplot  as plt
from neuron import h, gui

def resting_protocol(cell, start_seg=None):
    h.tstop = 1.0
    h.v_init = cell.soma[0].e_pas
    h.celsius = 37
    h.run()
    return 0, {}


os.makedirs(morph_path+'_plots', exist_ok=True)
for morph in glob(os.path.join(morph_path,'*')):
    print(morph)
    analyzer = Analyzer(morph_path=morph, type='ASC', more_conductances_protocol=resting_protocol)
    fig, ax = plt.subplots(1, 1)
    _ = analyzer.plot_morph(ax=ax, scale=250)
    plt.savefig(os.path.join(morph_path+'_plots', os.path.basename(morph).split('.')[0]+'.png'))
    plt.close()