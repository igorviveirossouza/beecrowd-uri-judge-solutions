# Lê o número de divisões (N)
N = int(input())

# Lê a lista de divisões e armazena como uma lista de inteiros
divisoes = list(map(int, input().split()))

# Calcula o total de pedaços armazenados, subtraindo 1 de cada divisão (o pedaço usado)
armazenados = sum(divisao - 1 for divisao in divisoes)

# Exibe o total de pedaços armazenados
print(armazenados)
