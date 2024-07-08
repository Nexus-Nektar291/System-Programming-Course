import socket

sockfd = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sockfd.bind(("0.0.0.0", 54154))
print("My echo server is listening at post : 54154")
while True:
    payload, client_addr = sockfd.recvfrom(1024)
    sockfd.sendto(payload, client_addr)
