entrada <- readLines(con = 'stdin')
N <- as.numeric(entrada[1])
pos.inicial <- 2
while(N > 0){
  escore.a <- 0
  escore.b <- 0
  #A = NULL; B = NULL
  for(i in pos.inicial: (pos.inicial + N - 1) ){
    A <- as.numeric(strsplit(entrada[i], " ")[[1]][1])
    B <- as.numeric(strsplit(entrada[i], " ")[[1]][2])
    if (A > B) {
      escore.a <- escore.a + 1
    } else if (A < B) {
      escore.b <- escore.b + 1
    } 
  }
  cat(c(escore.a,escore.b)); cat("\n")
  N <- as.numeric(entrada[i + 1])
  pos.inicial <- i+2
}
