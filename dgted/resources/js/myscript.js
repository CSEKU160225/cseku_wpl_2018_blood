$(document).ready(function(){
  $('.dropdown-submenu a.test').on("click", function(e){
    $(this).next('ul').toggle();
    e.stopPropagation();
    e.preventDefault();
  });
});

// sandbox disable popups
if (window.self !== window.top && window.name!="view1") {;
  window.alert = function(){/*disable alert*/};
  window.confirm = function(){/*disable confirm*/};
  window.prompt = function(){/*disable prompt*/};
  window.open = function(){/*disable open*/};
}
            
// prevent href=# click jump
document.addEventListener("DOMContentLoaded", function() {
  var links = document.getElementsByTagName("A");
  for(var i=0; i < links.length; i++) {
    if(links[i].href.indexOf('#')!=-1) {
      links[i].addEventListener("click", function(e) {
      console.debug("prevent href=# click");
          if (this.hash) {
            if (this.hash=="#") {
              e.preventDefault();
              return false;
            }
            else {
              /*
              var el = document.getElementById(this.hash.replace(/#/, ""));
              if (el) {
                el.scrollIntoView(true);
              }
              */
            }
          }
          return false;
      })
    }
  }
}, false);

function SetAllCheckBoxes(FormName, FieldName, CheckValue)
{
  if(!document.forms[FormName])
    return;
  var objCheckBoxes = document.forms[FormName].elements[FieldName];
  if(!objCheckBoxes)
    return;
  var countCheckBoxes = objCheckBoxes.length;
  if(!countCheckBoxes)
    objCheckBoxes.checked = CheckValue;
  else
    // set the check value for all check boxes
    for(var i = 0; i < countCheckBoxes; i++)
      objCheckBoxes[i].checked = CheckValue;
}

/*
 *  onChange event handler
 * getting the url and parsing and rebuilding it with selection information and finally redirect
 */
function onChangeEventHandler(event,obj){
   if(event != null){
    var url = window.location.href;
    url = url.indexOf("?") ? url.substring(0,url.indexOf("?")): url;  
    window.location = url + '?edit='+obj.value;
   }  
}

 

function printElement(elem, append, delimiter) {
    var domClone = elem.cloneNode(true);

    var $printSection = document.getElementById("printSection");

    if (!$printSection) {
        var $printSection = document.createElement("div");
        $printSection.id = "printSection";
        document.body.appendChild($printSection);
    }

    if (append !== true) {
        $printSection.innerHTML = "";
    }

    else if (append === true) {
        if (typeof(delimiter) === "string") {
            $printSection.innerHTML += delimiter;
        }
        else if (typeof(delimiter) === "object") {
            $printSection.appendChlid(delimiter);
        }
    }

 }


function printToast(message) {
    //var x = document.getElementById("toastME");
    //document.getElementById("toastME").innerHTML=message;
    //x.className = "show";
    //setTimeout(function(){ x.className = x.className.replace("show", ""); }, 3000);
    alert(message);
}