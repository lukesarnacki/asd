n, d = gets.chomp.split(" ").map(&:to_i)
result = gets.chomp.split(" ").map(&:to_i).reduce{|sum, n| sum + n}
i = 0
if d == 1
  i = n
else
  loop  { i+=1; break if (result = result / d) == 0 }
end
print i
