import thread
import socket
import time

temperatura = 0
fluxo = 20
comeco= time.clock()

def comunicacao(threadName, delay):
    global temperatura
    global fluxo
    global comeco

    HOST = ''# Symbolic name meaning all available interfaces
    PORT = 5000 # Arbitrary non-privileged port
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((HOST, PORT))
    s.listen(1)
    conn, addr = s.accept()
    print 'Connected by', addr

    while 1:
        pedido = conn.recv(1024)
        if not pedido:
            conn.sendall('ERRO')
            break

        elif pedido=="sensores":
            temperatura +=1
            if temperatura>500:
                temperatura = 0
            fluxo-=1
            if fluxo<0:
                fluxo=20
            tempo= time.clock()-comeco
            conn.sendall(str(fluxo)+" "+str(temperatura)+" "+str(tempo))
        conn, addr = s.accept()
        print 'Connected by', addr

    conn.close()


thread.start_new_thread(comunicacao,("comunicacao", 0.05,))

while 1:
    pass
