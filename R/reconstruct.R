reconstruct <- function(wavelet, scale = TRUE, method = c("quantile","range"), minQuantile = 0.01, maxQuantile = 0.99) {
  if(length(method) > 1) {
    method  <- "quantile"
  }
  reconstructed <- rowSums(Re(wavelet$scalogram))
  if(scale == FALSE){
    return(reconstructed)
  } else if (scale == TRUE){
    if (method == "quantile"){
      return((reconstructed - quantile(reconstructed,minQuantile))*(quantile(wavelet$signal,maxQuantile)- quantile(wavelet$signal,minQuantile))/(quantile(reconstructed,maxQuantile)- quantile(reconstructed,minQuantile)) + quantile(wavelet$signal,minQuantile))
    } else if (method == "range"){
      return((reconstructed - min(reconstructed))*(max(wavelet$signal)- min(wavelet$signal))/(max(reconstructed)- min(reconstructed)) + min(wavelet$signal))
    } else {
      stop("No reconstruction method specified. Try 'quantile' or 'range'.")
    }
  } else {
    stop("Invalid value for argument 'scale'. Specify a TRUE or FALSE value, or leave blank for the default value, TRUE")
  }
}