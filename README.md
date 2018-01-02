## RcppWavelet: An R/C++ Implemententation of Continuous Wavelet Transform

*Based on the [work of Jules Françoise and Frederic Bevilacqua at IRCAM](https://github.com/Ircam-RnD/wavelet)*

### Core Functionality

`RcppWavelet::analyze()` and `RcppWavelet::analyzeParallel()` are two functions that execute a continuous wavelet transform on an input numeric vector. Inputs and outputs are identical, but `analyzeParallel()` uses `openmp` to enable multi-threading. Since the calculation of coefficients for each band can be executed independently, the processing time is substantially reduced for each additional core used.

Two wavelets are currently implemented: Morlet and Paul.

```r
Wavelet <- RcppWavelet::analyzeParallel(signal,
                                        bands_per_octave = 128,
                                        frequency_min = 0.02,
                                        frequency_max = 0.5,
                                        samplerate_hz = 1,
                                        mother_wavelet = "MORLET",
                                        morlet_carrier = 30,
                                        cores = 6)
```
The returned object is a list of four elements:

+ signal: a normalized input vector of numeric values 
+ scalogram: a complex matrix representing the continuous wavelet transform of the input vector.
+ frequencies: the periods of each band calculated
+ periods: the corresponding periods for each band
+ configuration: a summary of the wavelet's parameters


### Helper functions

#### Signal Reconstruction

`RcppWavelet::reconstruct()` 

### Potential Further Development

+ Helper functions for input de-trending, filtering, and normalization
+ Implementation of FFTW in place of ARMA::FFT for improved speed
