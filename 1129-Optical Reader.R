entrada <- readLines(con = 'stdin')
N <- as.numeric(entrada[1])
pos.inicial <- 2
while(N > 0){
  for(i in pos.inicial:(pos.inicial+N-1) ){
    questao <- as.numeric(strsplit(entrada[i], " ")[[1]]) <= 127
    if(sum(questao)>=2 | sum(questao) == 0 ){
      cat('*\n')
    } else{
      if(which(questao) == 1){
        cat('A\n')
      } else if(which(questao) == 2){
        cat('B\n')
      } else if(which(questao) == 3){
        cat('C\n')
      } else if(which(questao) == 4){
        cat('D\n')
      } else if(which(questao) == 5){
        cat('E\n')
      }
    }
  }
  N <- as.numeric(entrada[i+1])
  pos.inicial <- (i+2) 
}
