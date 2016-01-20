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
   subprocess.check_call(["g++", "geomMain.o", "LineSegment.cpp", "Point.cpp" , "-o", "geom"])
except subprocess.CalledProcessError:
   print('\nCompilation encountered errors.\n')


#test 1
try:
   p = Popen(["./geom"], stdin=PIPE, stdout=subprocess.PIPE)

   alarm(5)

   try:
      str = p.communicate('1')[0]
      if str == 'pass\n':
         score += 12.5
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
   p = Popen(["./geom"], stdin=PIPE, stdout=subprocess.PIPE)

   alarm(5)

   try:
      str = p.communicate('2')[0]
      if str == 'pass\n':
         score += 12.5
      else:
         outFile.write("Test 2 failed.\n")
      alarm(0)
   except Alarm:
      print 'too long'
      p.kill()
except OSError:
   print('\nThe executable was not found.\n')


#test 3
try:
   p = Popen(["./geom"], stdin=PIPE, stdout=subprocess.PIPE)

   alarm(5)

   try:
      str = p.communicate('3')[0]
      if str == 'pass\n':
         score += 12.5
      else:
         outFile.write("Test 3 failed.\n")
      alarm(0)
   except Alarm:
      print 'too long'
      p.kill()
except OSError:
   print('\nThe executable was not found.\n')


#test 4
try:
   p = Popen(["./geom"], stdin=PIPE, stdout=subprocess.PIPE)

   alarm(5)

   try:
      str = p.communicate('4')[0]
      if str == 'pass\n':
         score += 12.5
      else:
         outFile.write("Test 4 failed.\n")
      alarm(0)
   except Alarm:
      print 'too long'
      p.kill()
except OSError:
   print('\nThe executable was not found.\n')


outFile.write("\nTotal score: " + repr(score) + "\n")
outFile.close()
