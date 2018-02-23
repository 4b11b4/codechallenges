#!/usr/bin/ruby

# Puppet Labs
# Software Engineer Intern - Installer Team Application
# 2/19/18
# Programming Challenge Option #1: Range, Sum, Print if Prime
# Description: # Generate a range of sequential numbers from 1 to 100000 (inclusive), and for each number in the range, add the digits of that number together. Print the sum of those digits if the sum is a prime number. Otherwise, print nothing.

require 'prime'

def printIfPrime(n)
  if Prime.prime?(n)
    puts n
  end
end

[*1..100000].each { |x| printIfPrime(x.to_s.chars.map(&:to_i).reduce(:+)) }
