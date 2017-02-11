#!/usr/bin/python3

import fileinput

vxs = []
tricount = 0;

for line in fileinput.input():
    line = line[:-1].split(' ')
    if line[0] == 'v':
        vxs += [line[1:]]
    elif line[0] == 'f':
        line = line[1:]
        tricount += 1
        for vxp in line:
            vx = vxs[int(vxp.split('//')[0])-1]
            for coord in vx:
                print(coord, end = ', ')
            print(end='\n')
        print(end='\n')

print(tricount, end=' triangles\n')
