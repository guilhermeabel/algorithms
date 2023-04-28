from enum import Enum

class TipoProduto(Enum):
    ENLATADO = 0
    REFRIGERADO = 1

class Produto:
    def __init__(self, Codigo = "indefinido", Tipo = TipoProduto.ENLATADO):
        self.Codigo = Codigo
        self.Tipo = Tipo

    def __repr__(self):
        return '%s -> %s' % (self.Codigo, self.Tipo.name)


class Nodo:
    def __init__(self, dado=None, proximo_nodo=None):
        self.conteudo = dado
        self.proximo = proximo_nodo

    def __repr__(self):
        return '%s -> %s' % (self.conteudo, self.proximo)

class ListaEncadeada:
    def __init__(self):
        self.inicio = None

    def __repr__(self):
        return "[" + str(self.inicio) + "]"

    def ListaVazia(self):
        return self.inicio is None

    def Push(self, produto):
        novo_nodo = Nodo(dado=produto)
        novo_nodo.proximo = self.inicio
        self.inicio = novo_nodo

    def ImprimeLista(self):
        atual = self.inicio
        cont = 0
        print("Início da Lista")

        if self.inicio is None:
            print("Lista Vazia")

        else:
            while atual is not None:
                print("Posição: ", cont, atual.conteudo)
                cont += 1
                atual = atual.proximo
        print("Final da Lista")
    
    def TotalRefrigerados(self):
        cont = 0
        atual = self.inicio
        while atual is not None:
            if atual.conteudo.Tipo == TipoProduto.REFRIGERADO:
                cont += 1
            atual = atual.proximo
        return cont

lista = ListaEncadeada()
lista.Push(Produto("001", TipoProduto.REFRIGERADO))
lista.Push(Produto("002", TipoProduto.ENLATADO))
lista.Push(Produto("003", TipoProduto.REFRIGERADO))
lista.Push(Produto("004", TipoProduto.ENLATADO))
lista.Push(Produto("005", TipoProduto.ENLATADO))
lista.Push(Produto("006", TipoProduto.ENLATADO))
lista.Push(Produto("007", TipoProduto.ENLATADO))
lista.Push(Produto("008", TipoProduto.ENLATADO))
lista.Push(Produto("009", TipoProduto.REFRIGERADO))

lista.ImprimeLista()

print("Total de produtos com Refrigeração: ", lista.TotalRefrigerados())
