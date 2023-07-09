"""
Create a basic .wav file that can be used in the wav_file_io testing
"""

import sys
from matplotlib import pyplot as plt
import numpy as np

sys.path.insert(0, '../../../code_lib_python/src')
import data_io as io

# create a signal
fs = 10000
[x,t] = io.createToneSig(1.0, 100, 1024, fs)

# write a wav file
io.writeWavFile(x, 'data/tone_input.wav', 1, 16, fs)

# reads a wav file
y = io.readWavFiles('data/tone_output.wav')

# error
print("error = %.4f" % np.sum(y-x))

# plotting
plt.plot(t,x, label='input')
plt.plot(t,y, label='output')
plt.grid()
plt.legend(loc='upper right')

plt.show()