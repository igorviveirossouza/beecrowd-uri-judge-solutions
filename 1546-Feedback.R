entradas <- readLines(con = "stdin")

# Converter a primeira linha para número (número de casos de teste)
N <- as.numeric(entradas[1])

# Inicializando índice de leitura da lista de entradas
indice <- 2

# Loop para processar cada caso de teste
for (caso in 1:N) {
  # Para cada caso de teste, primeiro pegue o valor de K (número de feedbacks)
  K <- as.numeric(entradas[indice])
  
  # Agora, processamos os próximos K feedbacks
  for (i in 1:K) {
    feedback <- as.numeric(entradas[indice + i])
    
    # Verificar o feedback e imprimir a pessoa responsável
    if (feedback == 1) {
      cat("Rolien\n")
    } 
    if (feedback == 2) {
      cat("Naej\n")
    } 
    if (feedback == 3) {
      cat("Elehcim\n")
    } 
    if (feedback == 4) {
      cat("Odranoel\n")
    }
  }
  
  indice <- indice + K + 1
}
