
require 'socket'

starttime = Process.clock_gettime(Process::CLOCK_MONOTONIC)

s = TCPSocket.new 'localhost', 8989

s.write("/tmp/testfiles/#{ARGV[0]}\n")

s.each_line do |line|
    puts line
end

s.close

endttime = Process.clock_gettime(Process::CLOCK_MONOTONIC)
elapsed = endttime - starttime
puts "Elapsed: #{elapsed}"