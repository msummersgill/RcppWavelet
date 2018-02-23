## RcppWavelet: An R/C++ Implemententation of Continuous Wavelet Transform

*Based on the [work of Jules Françoise and Frederic Bevilacqua at IRCAM](https://github.com/Ircam-RnD/wavelet)*

### Overview

The intent of the RcppWavelet package is to enable high performance wavelet analysis of time series data using R.

**A short vignette, [Using RcppWavelet](https://msummersgill.github.io/RcppWavelet/Using_RcppWavelet.nb.html), shows a simple use case.**

### Installation

System Requirements:

*This has only been tested on Ubuntu 14.04, and currently fails to compile on my Windows PC*

+ Armadillo - C++ Linear Algebra Library
+ Boost C++ Libraries
+ OpenMP

```r
library(devtools)
devtools::install_github("msummersgill/RcppWavelet")
```

### Core Functionality

`RcppWavelet::analyze()` executes a continuous wavelet transform on an input numeric vector. Specifying `cores > 1` uses `openmp` to enable multi-threading. Since the calculation of coefficients for each band can be executed independently, the processing time is substantially reduced for each additional core used.

Two wavelets are currently implemented: Morlet and Paul.

#### Input Parameters

+ `x`: A zero-mean, normalized numeric vector with no `NULL` values
+ `bands_per_octave`: Number of bands to calculate for each doubling of the frequency across the range
+ `frequency_min`: Min Frequency
+ `frequency_max`: Max Frequency
+ `samplerate_hz`: Input signal sample rate (Hertz)
+ `mother_wavelet`: Mother Wavelet, either "MORLET" or "PAUL"
+ `morlet_carrier`:  The carrier frequency for the Morlet Wavelet *(not relevant for Paul wavelet)*
+ `paul_order`:  The order of the Paul Wavelet to be used *(not relevant for Morlet wavelet)*
+ `cores`: number of threads to be created using `openMP`

```r
Wavelet <- RcppWavelet::analyze(x = signal_to_analyze,
                                bands_per_octave = 32,
                                frequency_min = 0.02,
                                frequency_max = 0.5,
                                samplerate_hz = 1,
                                mother_wavelet = "MORLET",
                                morlet_carrier = 30,
                                paul_order = 2,
                                cores = 6)
```

#### Output

The returned object is a list of five elements. 

+ `signal`: original input vector
+ `scalogram`: a complex matrix representing the continuous wavelet transform of the input vector.
+ `frequencies`: the periods of each band calculated
+ `periods`: the corresponding periods for each band
+ `configuration`: a summary of the wavelet's parameters


### Helper functions

#### Signal Reconstruction

`RcppWavelet::reconstruct()` 

Reconstructs signal based on wavelet transform.


### Potential Further Development

+ Helper functions for input de-trending, filtering, and normalization
+ Implementation of FFTW in place of ARMA::FFT for improved speed
