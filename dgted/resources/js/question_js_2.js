function generateCode(data){
    //Getting the number of option input
    var numOpt = document.getElementById(data+'NumOpt').value;
    //Grabbing option input area
    var optionInputArea = document.getElementById(data+'optInputArea');

    var heading1 = '<h4>Option';
    var heading2 = '</h4>';
    var inputArea1 = '<input type="text" class="form-control" value="" name="'+data+'Opt';
    var inputArea2 = '"/>';


    var html = '';
    var i;
    var intNumOpt = parseInt(numOpt);

    //Concat the html code
    for(i=1;i<=intNumOpt;i++){
        html += (heading1 + i.toString()+ heading2);
        html += (inputArea1+ i.toString()+inputArea2);
    }

    //Showing it in the browser
    optionInputArea.innerHTML = html;

}

