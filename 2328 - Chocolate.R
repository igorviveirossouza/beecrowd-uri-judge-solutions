entrada <- scan("stdin", what = integer())

N <- entrada[1]
total_armazenados <- sum(entrada[2:(N + 1)] - 1)
cat(total_armazenados)
cat("\n")
