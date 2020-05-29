import math

A,B,H,M=map(int,input().split())
ax = A * math.cos( (H/12 + M/60/12) * 2 * math.pi )
ay = A * math.sin( (H/12 + M/60/12) * 2 * math.pi )
bx = B * math.cos( M/60 * 2 * math.pi )
by = B * math.sin( M/60 * 2 * math.pi )
print( math.sqrt( (ax-bx)*(ax-bx) + (ay-by)*(ay-by) ) )

