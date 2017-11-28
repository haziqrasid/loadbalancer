require "socket"

while true
server=TCPSocket.open("192.168.32.129",3000)
loadbalancer=server.accept
puts loadbalancer.gets
loadbalancer.close
server.close
end

