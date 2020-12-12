import roslibpy
import socket


def get_ip():
    try:
        host_name = socket.gethostname()
        return socket.gethostbyname(host_name)
    except StandardError:
        print('Unable to get device ip')


ip = get_ip()
