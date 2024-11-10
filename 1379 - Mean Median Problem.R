options(scipen = 99999)
entrada <- readLines(con = "stdin")
for(i in 1:(length(entrada)) ){
  vetor <- as.numeric(strsplit(entrada[i]," ")[[1]])
  if(vetor[1]==0 & vetor[2]==0){
    #cat("\n")
    break
  } else{
    Valor <- round(2*min(vetor) - max(vetor))
    cat(Valor); cat("\n")
  }
}
