import roslibpy


def register_drone(client):
    service = roslibpy.Service(client, '/isaacs_server/register_drone', 'isaacs_server/register_drone')
    request = roslibpy.ServiceRequest({'drone_name': 'hexacopter', 'drone_type': 'MavrosDrone'})

    result = service.call(request)
    print('register_drone response: {}'.format(result))


server_ip = '192.168.254.35'
server_port = 9090
server_connection = roslibpy.Ros(host=server_ip, port=server_port)
server_connection.run(timeout=20)
if server_connection.is_connected:
    register_drone(server_connection)
