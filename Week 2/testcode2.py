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
   subprocess.check_call(["g++", "tempConvert.cpp", "-o", "temp"])
except subprocess.CalledProcessError:
   print('\nCompilation encountered errors.\n')


#test 1
try:
   p = Popen(["./temp"], stdin=PIPE, stdout=subprocess.PIPE)

   alarm(5)

   try:
      str = p.communicate('-40')[0]
      x = str.split('\n')
      if x[1] == '-40':
         score += 12.5
      else:
         outFile.write("test3 failed\n")
      alarm(0)
   except Alarm:
      print 'too long'
      p.kill()
except OSError:
   print('\nThe executable was not found.\n')


#test 2
try:
   p = Popen(["./temp"], stdin=PIPE, stdout=subprocess.PIPE)

   alarm(5)

   try:
      str = p.communicate('100')[0]
      x = str.split('\n')
      if x[1] == '212':
         score += 12.5
      else:
         outFile.write("test4 failed\n")
      alarm(0)
   except Alarm:
      print 'too long'
      p.kill()
except OSError:
   print('\nThe executable was not found.\n')

#test 3
try:
   p = Popen(["./temp"], stdin=PIPE, stdout=subprocess.PIPE)

   alarm(5)

   try:
      str = p.communicate('16')[0]
      x = str.split('\n')
      if x[1] == '60.8':
         score += 12.5
      else:
         outFile.write("test5 failed\n")
      alarm(0)
   except Alarm:
      print 'too long'
      p.kill()
except OSError:
   print('\nThe executable was not found.\n')


#test 4
try:
   p = Popen(["./temp"], stdin=PIPE, stdout=subprocess.PIPE)

   alarm(5)

   try:
      str = p.communicate('1000')[0]
      x = str.split('\n')
      if x[1] == '1832':
         score += 12.5
      else:
         outFile.write("test5 failed\n")
      alarm(0)
   except Alarm:
      print 'too long'
      p.kill()
except OSError:
   print('\nThe executable was not found.\n')


outFile.write("\nTotal score: " + repr(score) + "\n")
outFile.close()
