#!/usr/bin/ruby

# Puppet Labs
# Software Engineer Intern - Installer Team Application
# 2/19/18
# Programming Challenge Option #2: Average Stopwatch Time
# Description: A stopwatch records lap times as strings of the form "MM:SS:HS", where MM = minutes, SS = seconds, and HS = hundredths of a second. Write a program or script that accepts two lap times and calculates their average, returning the result in the same string format. For example, given the strings "00:02:20" and "00:04:40" the solution would return "00:03:30".

# This function checks that the user input is in the valid format.
def validTime(string)
  # Check for expected length
  if string.length == 8
    # do nothing, length is valid
  else
    puts "The time that you entered was not in the correct format.\nERROR: incorrect length."
    return false
  end

  # Delimiter in proper position
  valid_delimiter = true if string[2] == ":" and string[5] == ":"
  if string[2] == ":" and string[5] == ":"
    # do nothing, delimiters in correct position
  else
    puts "The time that you entered was not in the correct format.\nERROR: Colons were not in their expected positions."
    return false
  end

  # Valid integer values
  numbers = string.split(":")
  for i in numbers

    # Remove a preceding zero if there is one
    if i[0] == "0"
      i = i[1]
      #puts "Removed preceeding zero."
    end

    # Check that we didn't convert any other characters to an integer in a somewhat obscure way by converting the input string to an integer and back to a string again. This takes care of the case where to_i will convert non integer characters to zero which are then valid integers in the check below.
    if not i.to_i.to_s == i
      puts "The time that you entered was not in the correct format.\nERROR: Invalid non-integer characters."
      return false
    end
    
    # Check that the number is between 0 and 99
    # I'm not certain that this needs to occur after we check above that the characters were already integers.
    i = i.to_i
    if i < 100 and i > -1
      # do nothing, valid integer value
    else
      puts "The time that you entered was not in the correct format.\nERROR: Integer values not between 00 and 99."
      return false
    end
  end

  return true

end

## Program Start
puts "Welcome to the stopwatch time addition program!"
puts "This program will take two times and average them. Times must be in the format 'MM:SS:HS' where MM is minutes, SS is seconds, and HS is hundredths of a second. Don't forget your colons!"

# Get Time #1
valid_time = false
until valid_time == true
  puts "\nPlease enter Time #1:"
  t1 = gets.chomp
  valid_time = validTime(t1)
end
puts "Thank you for entering Time #1."

# Get Time #2
valid_time = false
until valid_time == true
  puts "\nPlease enter Time #2:"
  t2 = gets.chomp
  valid_time = validTime(t2)
end
puts "Thank you for entering Time #2."

# Get the integer values between the colons
t1 = t1.split(":").map{ |s| s.to_i }
t2 = t2.split(":").map{ |s| s.to_i }
# Add the values together
total = [t1,t2].transpose.map{ |x| x.reduce(:+) }
# Divide by 2 for the average
average = total.collect{ |t| t / 2 }
# Convert values back to a string
string_total = average.map{ |i| i.to_s }
# Prepend a 0 if single digit integer
average.length.times do |i|
  if average[i] < 10
    string_total[i].insert(0, "0")
  end
end

# Print the result
average = string_total[0] + ":" + string_total[1] + ":" + string_total[2]
puts "\nThe average of Time #1 and Time #2 is:\n#{average}"
