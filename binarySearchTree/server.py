from re import S
from socket import *
serverport=12000
serversocket = socket(AF_INET,SOCK_DGRAM);
serversocket.bind(('',serverport))
print("The server is ready to receive")





while True:

    msg,clientaddress = serversocket.recvfrom(2048);
    modifiedmsg=msg.decode().upper();
    serversocket.sendto(modifiedmsg.encode(),clientaddress)
