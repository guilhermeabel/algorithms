
class Produto:
    def __init__(self, codigo=0, proximo_nodo=None):
        self.codigo = codigo
        self.proximo = proximo_nodo

    def __repr__(self):
        return '%s -> %s' % (self.codigo, self.proximo)

class ListaEncadeada:
    def __init__(self):
        self.cabeca = None

    def __repr__(self):
        return "[" + str(self.cabeca) + "]"
    
    def AddFinal(self, novoCod):
        novoNo = Produto(novoCod)
        
        if self.cabeca is None:
            self.cabeca = novoNo
        else:
            atual = self.cabeca
            while atual.proximo is not None:
                atual = atual.proximo
            atual.proximo = novoNo

lista = ListaEncadeada()
lista.AddFinal(10010101)
print(lista)
lista.AddFinal(10100110)
print(lista)
lista.AddFinal(10011110)
print(lista)
lista.AddFinal(11101110)
print(lista)
