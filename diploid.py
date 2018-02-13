from tandem_repeat import Tandem_repeat
import random
import copy


class Diploid:
    conversionrate = 1

    def __init__(self, l1, l2, i1=None, s1=0.0):
        self._paternal = Tandem_repeat(l1, i1, s1)
        self._maternal = Tandem_repeat(l2)

    def get_ids(self):
        ids = [self._paternal.get_ids(), self._maternal.get_ids()]
        return ids

    def get_fitnesses(self):
        fitnesses = [self._paternal.get_fitnesses(),
                     self._maternal.get_fitnesses()]
        return fitnesses

    def gene_conversion(self):
        r = random.random()
        next_diploid = copy.deepcopy(self)
#        if r < Diploid.conversionrate:
#            donor = random.choice()
#            recip = random.randint(0, 1)
#            next_diploid[recip] = donor
        return next_diploid


test = Diploid(3, 2, 2, 0.2)
print(test.get_ids())
print(test.get_fitnesses())


test2 = test.gene_conversion()
print(test2.get_ids())
print(test2.get_fitnesses())
