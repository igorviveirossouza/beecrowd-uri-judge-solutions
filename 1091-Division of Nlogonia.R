entrada <- readLines(con = 'stdin')
K <- as.numeric(entrada[1])
N <- as.numeric(strsplit(entrada[2], " ")[[1]][1])
M <- as.numeric(strsplit(entrada[2], " ")[[1]][2])
pos.inicial <- 3
while(K > 0){
  for(j in pos.inicial: (pos.inicial + K - 1) ){
    nn = as.numeric(strsplit(entrada[j], " ")[[1]][1])
    mm = as.numeric(strsplit(entrada[j], " ")[[1]][2])
    if(nn == N | mm == M){
      cat("divisa\n")
    } else if(nn > N & mm > M){
        cat("NE\n")
    } else if(nn > N & mm < M){
        cat("SE\n")
    } else if(nn < N & mm > M){
        cat("NO\n")
    } else if(nn < N & mm < M){
        cat("SO\n")
    }
    
  }
  K <- as.numeric(entrada[j + 1])
  N <- as.numeric(strsplit(entrada[j+2], " ")[[1]][1])
  M <- as.numeric(strsplit(entrada[j+2], " ")[[1]][2])
  pos.inicial <- j+3
  
}
