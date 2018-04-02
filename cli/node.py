###############################################################################
#   @file       scripts/node.py
#   @brief      Node to test.
#   @author     llHoYall <hoya128@gmail.com>
#   @version    v1.0
#   @note
#       - 2018.04.02    Created.
###############################################################################

# Import Packages ------------------------------------------------------------#
# Built-In
import os
import time
import pexpect


# Node Class -----------------------------------------------------------------#
class Node:
    def __init__(self, nodeid):
        self.nodeid = nodeid

        cmd = 'build/cli'
        self.pexpect = pexpect.spawn(cmd, timeout=4)
        time.sleep(0.2)

    def send_command(self, cmd):
        print(cmd)
        self.pexpect.send(cmd + '\n')

    def test(self):
        self.send_command('Test')
        self.pexpect.expect('Done')

    def stop(self):
        self.send_command('Exit')
