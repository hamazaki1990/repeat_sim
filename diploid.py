from Tandem_repeat import Tandem_repeat


class Diploid:
    conversionrate = 0.01

    def __init__(self, l1, l2, i1=None, s1=0.0):
        self._diploid = [Tandem_repeat(l1, i1, s1), Tandem_repeat(l2)]

    def gene_conversion(self):
        
