#!/usr/bin/python3                                                                                                                              
"""
Main file for testing
"""

def minOperations(n):                                                                                                                           
    "This is a line of text"
    if n < 2:                                                                                                                               
        return 0                                                                                                                        
    res, fac = 0, 2                                                                                                                         
    while n > 1:                                                                                                                            
        while n % fac == 0:                                                                                                             
            res += fac                                                                                                              
            n /= fac                                                                                                                
        fac += 1                                                                                                                        
    return res
