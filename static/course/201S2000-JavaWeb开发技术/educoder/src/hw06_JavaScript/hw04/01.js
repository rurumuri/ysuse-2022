function Car(plate,owner) {
    this.plate = plate;
    this.owner = owner;
}

function Job() {};
Job.prototype.company = "myCompany";
Job.prototype.salary = 12000;

function mainJs(a,b,c,d,e) {
    //请在此处编写代码
    /*********bigin*********/
    var student = {
        name:a,
        gender:b
    };
    var myCar = new Car(c, d);
    var myJob = new Job();
    myJob.company = e;
    /*********end*********/
    return student.name+student.gender+myCar.plate+myCar.owner+myJob.company;
}