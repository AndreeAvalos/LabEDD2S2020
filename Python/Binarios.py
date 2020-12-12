import pickle

def commit(objeto, nombre):
    file = open(nombre+".bin","wb+")
    file.write(pickle.dumps(objeto))
    file.close()

def rollback(nombre):
    file = open(nombre+".bin", "rb")
    b = file.read()
    file.close()
    return pickle.loads(b)