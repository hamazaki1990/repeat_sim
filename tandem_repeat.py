from monomer import monomer


class Tandem_repeat:
    def __init__(self, n, i=None, s=0.0):
        inds = [Monomer(x) for x in range(n)]
