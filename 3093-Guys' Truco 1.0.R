# Escreva a sua solução aqui
# Code your solution here
# Escriba su solución aquí

entrada <- strsplit(readLines(con = 'stdin'), " ")
teste.cases <- as.numeric(entrada[[1]])
pos.inicial <- 2
for(i in pos.inicial:(pos.inicial + teste.cases - 1)){
  #cartas a serem encontradas: Q, J, K, A 
  cartas       <- c(FALSE,FALSE,FALSE,FALSE)
  for(j in 1:nchar(entrada[[i]])){
    if(substr(entrada[[i]],j,j) == "Q"){
      cartas[1] <- TRUE
    } else if(substr(entrada[[i]],j,j) == "J"){
      cartas[2] <- TRUE 
    } else if(substr(entrada[[i]],j,j) == "K"){
      cartas[3] <- TRUE 
    } else if(substr(entrada[[i]],j,j) == "A"){
      cartas[4] <- TRUE 
    }
    if(sum(cartas)==4){
      cat("Aaah muleke"); cat("\n")
      break
    } else if((sum(cartas) < 4) & (j == nchar(entrada[[i]]))){
      cat("Ooo raca viu"); cat("\n")
    }
  }
}
