import random


class Lance:
    def __init__(self, id, valor):
        self.id = id
        self.valor = valor
        self.proximo = None

class Leilao:
    def __init__(self):
        self.primeiro_lance = None
    
    def adicionar_lance(self, id, valor):
        novo_lance = Lance(id, valor)
        
        if self.primeiro_lance is None:
            self.primeiro_lance = novo_lance
        else:
            atual = self.primeiro_lance
            while atual.proximo is not None:
                atual = atual.proximo
            atual.proximo = novo_lance
    
    def excluir_lance(self, id):
        if self.primeiro_lance is None:
            return
        
        if self.primeiro_lance.id == id:
            self.primeiro_lance = self.primeiro_lance.proximo
            return
        
        atual = self.primeiro_lance
        while atual.proximo is not None:
            if atual.proximo.id == id:
                atual.proximo = atual.proximo.proximo
                return
            atual = atual.proximo
    
    def maior_lance(self):
        if self.primeiro_lance is None:
            return None
        
        maior_lance = self.primeiro_lance.valor
        atual = self.primeiro_lance.proximo
        
        while atual is not None:
            if atual.valor > maior_lance:
                maior_lance = atual.valor
            atual = atual.proximo
        
        return maior_lance
    
    def identificador_vencedor(self):
        if self.primeiro_lance is None:
            return None
        
        maior_lance = self.maior_lance()
        
        atual = self.primeiro_lance
        while atual is not None:
            if atual.valor == maior_lance:
                return atual.id
            atual = atual.proximo


leilao = Leilao()

# Adiciona 5 lances aleatórios ao leilão
for i in range(5):
    id = i + 1
    valor = random.randint(100, 1000)
    leilao.adicionar_lance(id, valor)
    print(f'Lance adicionado: id = {id}, valor = {valor}')

# Exibe o maior lance e o identificador do vencedor
maior_lance = leilao.maior_lance()
vencedor = leilao.identificador_vencedor()

if maior_lance is None:
    print('Nenhum lance foi dado')
else:
    print(f'O maior lance foi de {maior_lance}')
    if vencedor is None:
        print('Não houve vencedor')
    else:
        print(f'O vencedor foi o lance de id {vencedor}')
