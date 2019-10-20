//Tower of Hanoi problem implementation
def towerOfHanoi(disks, source, auxiliary, target):
    if disks == 1:
        print('Move disk 1 from peg {} to peg {}.'.format(source, target))
        return
 
    towerOfHanoi(disks - 1, source, target, auxiliary)
    print('Move disk {} from peg {} to peg {}.'.format(disks, source, target))
    towerOfHanoi(disks - 1, auxiliary, source, target)
 
 
disks = int(input('Enter number of disks: '))
towerOfHanoi(disks, 'A', 'B', 'C')
