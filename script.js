$(window).scroll(function () {
    if ($(document).scrollTop() > 50) {
        $('.nav').addClass('affix');
        console.log("OK");
    } else {
        $('.nav').removeClass('affix');
    }
});

$('.navTrigger').click(function () {
    $(this).toggleClass('active');
    console.log("Clicked menu");
    $("#mainListDiv").toggleClass("show_list");
    $("#mainListDiv").fadeIn();

});

// document.querySelectorAll(".navTrigger").forEach((element)=>{
//     element.addEventListener("click", () => {
//         element.classList.toggle('active');
//         console.log("Clicked menu");
//         document.getElementById("mainListDiv").classList.toggle("show_list");
//         $("#mainListDiv").fadeIn();
//         // element.classList.add('show');
//         // element.classList.remove('hide');
//     });
// });
