entradas <- readLines(con='stdin')

for(i in 1:length(entradas)){
  if(strsplit(entradas[[i]]," ")[[1]][1] ==
     strsplit(entradas[[i]]," ")[[1]][2] &
     strsplit(entradas[[i]]," ")[[1]][2] == "0"){
    break
  }    
  cat(
    sum(
      as.numeric(
        strsplit(entradas[[i]]," ")[[1]]
      )
    )
  )
  cat("\n")
}
