require "socket"

while true
server=TCPSocket.open("192.168.32.128",2000)
loadbalancer=server.accept
puts loadbalancer.gets
loadbalancer.close
server.close
end

