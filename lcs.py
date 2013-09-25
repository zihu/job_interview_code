#!/usr/bin/python

def lcs(xs, ys):
  '''Return a longest common subsequence of xs and ys.
     Example
     >>> lcs("HUMAN", "CHIMPANZEE")
     ['H', 'M', 'A', 'N']
  '''
  if xs and ys:
    xb = xs[:-1]
    yb = ys[:-1]
    if xs[-1] == ys[-1]:
      return lcs(xb, yb) + [xs[-1]]
    else:
      return max(lcs(xs, yb), lcs(xb, ys), key=len)
  else:
    return []

def lcs_len(x, y):
  """This function returns length of longest common sequence of x and y."""
  if len(x) == 0 or len(y) == 0:
    return 0

  xx = x[:-1]   # xx = sequence x without its last element    
  yy = y[:-1]
			     
  if x[-1] == y[-1]:  # if last elements of x and y are equal
    return lcs_len(xx, yy) + 1
  else:
    return max(lcs_len(xx, y), lcs_len(x, yy))

if __name__ == '__main__':
  s1="hemllyoname"
  s2="whatisyournamehello"
#n=lcs_len(s1, s2)
#print n
  print lcs(s1, s2)
