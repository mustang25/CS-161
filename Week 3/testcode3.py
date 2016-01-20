from signal import alarm, signal, SIGALRM
import subprocess
from subprocess import Popen
from subprocess import PIPE
import os

score = 0
outFile = open("results.txt", "w")

class Alarm(Exception):
   pass

def alarm_handler(signum, frame):
   raise Alarm

signal(SIGALRM, alarm_handler)

try:
   subprocess.check_call(["g++", "numGuess.cpp", "-o", "numGuess"])
except subprocess.CalledProcessError:
   print('\nCompilation encountered errors.\n')


# test 1
try:
   p = Popen(["./numGuess"], stdin=PIPE, stdout=subprocess.PIPE)
   alarm(5)

   try:
      str = p.communicate('42\n10\n20\n80\n42')[0]
      x = str.split('\n')
      y = x[8].split()
      if x[2] == "higher" and x[4]== "higher" and x[6] == "lower" and y[4] == "4":
         score += 25
      else:
         outFile.write("Test 1 failed.\n")
      alarm(0)
   except Alarm:
      print 'too long'
      p.kill()
except OSError:
   print('\nThe executable was not found.\n')


#test 2
try:
   p = Popen(["./numGuess"], stdin=PIPE, stdout=subprocess.PIPE)

   alarm(5)

   try:
      str = p.communicate('-100\n2\n-217\n-100')[0]
      x = str.split('\n')
      y = x[6].split()
      if x[2] == "lower" and x[4] == "higher" and y[4] == "3":
         score += 25
      else:
         outFile.write("Test 2 failed.\n")
      alarm(0)
   except Alarm:
      print 'too long'
      p.kill()
except OSError:
   print('\nThe executable was not found.\n')


outFile.write("\nTotal score: " + repr(score) + "\n")
outFile.close()
