#include <RcppArmadillo.h>
#include "wavelet_all.hpp"

#define USE_ARMA
using namespace Rcpp;
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
Rcpp::List analyze(std::vector<double> x,
                             float bands_per_octave = 8,
                             float frequency_min = 0.001953125,
                             float frequency_max = 0.5,
                             float samplerate_hz = 1,
                             std::string mother_wavelet = "MORLET") {
  wavelet::Filterbank cwt(samplerate_hz,
                          frequency_min,
                          frequency_max,
                          bands_per_octave);
  if (mother_wavelet == "MORLET") {
    cwt.setAttribute("family",wavelet::Family::MORLET);
  } else if (mother_wavelet == "PAUL") {
    cwt.setAttribute("family",wavelet::Family::PAUL);
  } else {
    throw std::runtime_error("Invalid mother_wavelet. Try 'MORLET' or 'PAUL'");
  }
  
  std::size_t numbands(cwt.size());
  cwt.reset();
  arma::cx_mat scalogram = cwt.process(x);
  std::vector<double> frequencies = cwt.frequencies;
  arma::vec periods = 1/arma::conv_to<arma::vec>::from(frequencies); 
  std::string configuration = cwt.info();
  return Rcpp::List::create(Rcpp::Named("scalogram")=scalogram,
                            Rcpp::Named("periods")=periods,
                            Rcpp::Named("configuration")=configuration);
}

// [[Rcpp::export]]
Rcpp::List analyzeParallel(std::vector<double> x,
                             float bands_per_octave = 8,
                             float frequency_min = 0.001953125,
                             float frequency_max = 0.5,
                             float samplerate_hz = 1,
                             int cores = 1,
                             std::string mother_wavelet = "MORLET",
                             std::string optimisation = "NONE") {
  
  wavelet::Filterbank cwt(samplerate_hz,
                          frequency_min,
                          frequency_max,
                          bands_per_octave);
  
  if (mother_wavelet == "MORLET") {
    cwt.setAttribute("family",wavelet::Family::MORLET);
  } else if (mother_wavelet == "PAUL") {
    cwt.setAttribute("family",wavelet::Family::PAUL);
  } else {
    throw std::runtime_error("Invalid mother_wavelet. Try 'MORLET' or 'PAUL'");
  }
  
  cwt.setAttribute("optimisation",wavelet::Filterbank::Optimisation::STANDARD);
  
  std::size_t numbands(cwt.size());
  cwt.reset();
  arma::cx_mat scalogram = cwt.processParallel(x, cores);
  std::vector<double> frequencies = cwt.frequencies;
  arma::vec periods = 1/arma::conv_to<arma::vec>::from(frequencies); 
  std::string configuration = cwt.info();
  return Rcpp::List::create(Rcpp::Named("scalogram")=scalogram,
                            Rcpp::Named("periods")=periods,
                            Rcpp::Named("configuration")=configuration);
}
