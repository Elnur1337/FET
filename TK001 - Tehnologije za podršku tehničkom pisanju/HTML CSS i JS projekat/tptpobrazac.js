const aktivnaStr = window.location.pathname;

const navLinks = document.querySelectorAll('nav a').forEach(link => {
    if(link.href.includes(`${aktivnaStr}`)) {
        link.classList.add('active');
    }
});

let firstNameField = document.querySelector("#firstName");
let lastNameField = document.querySelector("#lastName");
let phoneNumberField = document.querySelector("#phoneNumber");
let emailField = document.querySelector("#email");
let msgField = document.querySelector("#msg");

const contactForm = document.querySelector("#contactForm");
const msgBox = document.querySelector(".msgBox");

const showErrorMsg = () => {
    msgBox.classList.remove("validMsg");
    msgBox.classList.add("errorMsg");
    msgBox.classList.remove("d-none");
    msgBox.innerHTML = "Niste ispravno popunili sva polja!";
    const showErrorMsgTime = setInterval(() => {
        msgBox.classList.add("d-none");
        return clearInterval(showErrorMsgTime);
    }, 5000);
}

const showValidMsg = () => {
    msgBox.classList.remove("errorMsg");
    msgBox.classList.add("validMsg");
    msgBox.classList.remove("d-none");
    msgBox.innerHTML = "Poruka poslana!";
    const showErrorMsgTime = setInterval(() => {
        msgBox.classList.add("d-none");
        return clearInterval(showErrorMsgTime);
    }, 5000);
}
if (contactForm) {
    contactForm.addEventListener("submit", (e) => {
        let isError = false;
        const firstName = firstNameField.value;
        const lastName = lastNameField.value;
        const phoneNumber = phoneNumberField.value;
        const email = emailField.value;
        const msg = msgField.value;
        e.preventDefault();
        if (firstName.length < 2 || firstName.length > 15) {
            isError = true;
            showErrorMsg();
        }
        if (lastName.length < 2 || lastName.length > 15) {
            isError = true;
            showErrorMsg();
        }
        if (phoneNumber.length < 5 || phoneNumber.length > 12) {
            isError = true;
            showErrorMsg();
        }
        if (!(/^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/.test(email))) {
            isError = true;
            showErrorMsg();
        }
        if (msg.length < 5) {
            isError = true;
            showErrorMsg();
        }
        if (!isError) {
            firstNameField.value = "";
            lastNameField.value = "";
            phoneNumberField.value = "";
            emailField.value = "";
            msgField.value = "";
            showValidMsg();
        }
    });
}


const allFilterItems = document.querySelectorAll('.filter-item');
const allFilterBtns = document.querySelectorAll('.filter-btn');

function resetActiveBtn(){
    allFilterBtns.forEach((btn) => {
        btn.classList.remove('active-btn');
    });
};

function showFilteredContent(btn){
    allFilterItems.forEach((item) => {
        if(item.classList.contains(btn.id)){
            resetActiveBtn();
            btn.classList.add('active-btn');
            item.style.display = "flex";
  
        } else {
            item.style.display = "none";
        }
    });
}

allFilterBtns.forEach((btn) => {
    btn.addEventListener('click', () => {
        showFilteredContent(btn);
    })
});

let vise = document.querySelectorAll('.filter-item');
let btn2 = document.querySelector('.btn2');
let btn3 = document.querySelectorAll('.filter-btn');

let trenutna = 3;

if (btn2) {
    btn2.addEventListener('click',function() {
      for(let i=trenutna; i<trenutna+4;i++) {
        if (vise[i]) {
          vise[i].style.display='flex';
        }
      }
      trenutna+=4;
      if (trenutna>=vise.length) {
        btn2.style.display='none';
      }
    });
    btn3.forEach(function(button) {
      button.addEventListener('click',function() {
       btn2.style.display='none';
      console.log('hi');
    }); 
    });
}

const numbers  = document.querySelectorAll('.number');
numbers.forEach(number => {
  number.addEventListener('click', () => {
    numbers.forEach(number => number.classList.remove('active1'));
    number.classList.add('active1');
  });
});

window.onload = function() {
    let link = document.querySelector('.clickable-link');
    let target = document.getElementById('container');
    let button5 = document.querySelector('.btn2');
    
    ;
    
    link.addEventListener('click', function(event) {
    event.preventDefault();
    button5.click();
    target.classList.add('shadow');
    setTimeout(function() {
    target.classList.remove('shadow');
    }, 2000);
    target.scrollIntoView({behavior: 'smooth'});
    });
   };
