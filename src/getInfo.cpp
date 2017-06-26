#include "wavelet_all.hpp"
#include "filterbank.hpp"

using namespace Rcpp;

// [[Rcpp::export]]
std::vector<double> getScales(float bands_per_octave = 8,
                              float frequency_min = 0.001953125,
                              float frequency_max = 0.5,
                              float samplerate_hz = 1) {
  wavelet::Filterbank cwt(samplerate_hz,
                          frequency_min,
                          frequency_max,
                          bands_per_octave);
  return cwt.scales;
}

// [[Rcpp::export]]
std::size_t getSize(float bands_per_octave = 8,
                              float frequency_min = 0.001953125,
                              float frequency_max = 0.5,
                              float samplerate_hz = 1) {
  wavelet::Filterbank cwt(samplerate_hz,
                          frequency_min,
                          frequency_max,
                          bands_per_octave);
  return cwt.size();
}
