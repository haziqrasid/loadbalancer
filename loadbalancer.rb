require "socket"
ld=TCPSocket.open("192.168.23.129",1000)

while true
c=ld.accept

rhost=c.peeraddr.last
puts "#{rhost} connect to loadbalancer"

client=c.gets
puts "message from client: #{client}"

if client=="server 1"
server1=TCPSocket.open("192.168.32.128",2000)
server1.write(client)
server1.close

elsif client=="server 2"
server2=TCPSocket.open("192.168.32.129",3000)
server2.write(client)
server2.close

else
puts "ERROR!!"

end
end

