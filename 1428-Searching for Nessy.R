# Escreva a sua solução aqui
# Code your solution here
# Escriba su solución aquí
options(scipen = 99999)
entrada <- strsplit(readLines(con = 'stdin'), " ")
teste.cases <- as.numeric(entrada[[1]])
pos.inicial <- 2
saida       <- NULL
for(i in pos.inicial:(pos.inicial + teste.cases - 1)){
  # Tamanho do grid
  # Calcular o número de sonares diretamente
  # Cada sonar cobre 3x3, então subtraímos 1 (para cada borda que não precisa ser monitorada), 
  # dividimos o grid por 3 e arredondamos para o inteiro mais próximo

  n.rows <- round((as.numeric(entrada[[i]][1])-1)/3)
  n.cols <- round((as.numeric(entrada[[i]][2])-1)/3)
 
  # O número total de sonares é o produto dos dois
  sonares <- n.rows * n.cols
  # Exibir resultado
  cat(sonares); cat("\n")
}
