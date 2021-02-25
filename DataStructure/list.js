function List() {
    this.listSize = 0;
    this.pos = 0;
    this.dataStore = [];
    this.clear = clear;
    this.find = find;
    this.toString = toString;
    this.insert = insert;
    this.append = append;
    this.remove = remove;
    this.front = front;
    this.end = end;
    this.prev = prev;
    this.next = next;
    this.length = length;
    this.currPos = currPos;
    this.moveTo = moveTo;
    this.getElement = getElement;
    this.contains = contains;
    
    function append(element) {
        this.dataStore[this.listSize++] = element;
    }

    function find(element) {
        for (var i = 0; i < this.dataStore.length; ++i) {
            if (this.dataStore[i] == element) {
                return i;
            }
        }
        return -1;
    }

    function remove(element) {
        var foundAt = this.find(element);
        if (foundAt > -1) {
            this.dataStore.splice(foundAt, 1);
            --this.listSize;
            return true;
        }
        return false;
    }

    function length() {
        return this.listSize;
    }

    function toString() {
        return this.dataStore;
    }

    function insert(element, after) {
        var insertPos = this.find(after);
        if (insertPos > -1) {
            this.dataStore.splice(insertPos + 1, 0, element);
            ++this.listSize;
            return ture;
        }
        return false;
    }

    function clear() {
        delete this.dataStore;
        this.dataStore.length = 0;
        this.listSize = this.pos = 0;
    }

    function contains(element) {
        for (var i = 0; i < this.dataStore.length; ++i) {
            if (this.dataStore[i] == element) {
                return true;
            }
        }
        return false;
    }

    function front() {
        this.pos = 0;
    }

    function end() {
        this.pos = this.listSize - 1;
    }

    function prev() {
        --this.pos;
    }

    function next() {
        if (this.pos < this.listSize) {
            ++this.pos;
        }
    }

    function currPos() {
        return this.pos;
    }

    function movtTo(position) {
        this.pos = position;
    }

    function getElement() {
        return this.dataStore[this.pos];
    }

    function hasNext() {
        return this.pos < this.listSize;
    }

    function hasPrev() {
        return this.pos >= 0;
    }
}

var names = new List();
names.append("Cynthia");
names.append("Raymond");
names.append("Barbara");
console.log(names.toString());
names.remove("Raymond");
console.log(names.toString());


function createArr(data) {
    var arr = data;
    for (var i = 0; i < arr.length; ++i) {
        arr[i] = arr[i].trim();
    }
    return arr;
}

function displayList(list) {
    for (list.front(); list.currPos() < list.length(); list.next()) {
        if (list.getElement() instanceof Customer) {
            console.log(list.getElement()['name'] + ', ' + list.getElement()['movie']);
        } else {
            console.log(list.getElement());
        }
    }
}

var customers = new List();

function Customer(name, movie) {
    this.name = name;
    this.movie = movie;
}

function checkOut(name, movie, movieList, customerList) {
    if (movieList.contains(movie)) {
        var c = new Customer(name, movie);
        customerList.append(c);
        movieList.remove(movie);
    } else {
        console.log(movie + 'is not available.');
    }
}

var data = ['The Shawshank Redemption', 'The Godfather'];

var movies = createArr(data);
var movieList = new List();
var customers = new List();
for (var i = 0; i < movies.length; ++i) {
   movieList.append(movies[i]);
}
console.log("All movies: ");
displayList(movieList);
checkOut("Jane Doe", "The Godfather", movieList, customers);
console.log("Customer Rentals: ");
displayList(customers);
console.log("Available movies: ");
displayList(movieList);