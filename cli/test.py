#!/usr/bin/env python3
###############################################################################
#   @file       scripts/test.py
#   @brief      Test scripts.
#   @author     llHoYall <hoya128@gmail.com>
#   @version    v1.0
#   @note
#       - 2018.04.02    Created.
###############################################################################

# Import Packages ------------------------------------------------------------#
# Built-In
import unittest
# System
import node


# Test Class -----------------------------------------------------------------#
class ProtocolTest(unittest.TestCase):
    def setUp(self):
        self.node = node.Node(0)

    def tearDown(self):
        self.node.stop()
        del self.node

    def test(self):
        self.node.test()


# Main Routine ---------------------------------------------------------------#
if __name__ == '__main__':
    unittest.main()
