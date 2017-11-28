require "socket"
c=TCPSocket.open("192.168.23.129",1000)

puts "Enter your message: "
mesage=gets.chomp

rhost=c.peeraddr.last
puts "#{rhost}"
c.write(message)
c.close