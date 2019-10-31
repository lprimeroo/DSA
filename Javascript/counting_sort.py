elements = [55,12,13,99,7]
maxSize = Math.max(...elements)
minSize = Math.min(...elements)
temp = new Array()
function oneArrayElements(element, index, array) {
    temp[element]=1
}
elements.forEach(oneArrayElements);
b = new Array()


function orderArrayElements(element, index, array) {
   if (element==1)
       b.push(index)
}

temp.forEach(orderArrayElements);

b
