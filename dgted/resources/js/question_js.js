/**
 * Created by Abbir on 4/12/2017.
 */
function createOptionInput(data){
    var html1 = '';
    var html2 = '';
    var html3 = '';
    var totalHTML = '';

    html1 += '<div class="row">';
    html1 += '<div class="col-md-12">';
    html1 += '<div class="form-group">';
    html1 += '<div class="col-md-2">';
    html1 += '<h4 class="col-2 col-form-label">Option';
    html2 += ' </h4>'; //hmm
    html2 += '</div>';
    html2 += '<div class="col-md-offset-1 col-md-4">';
    html2 += '<input class="form-control" type="text" value="" id="field';
    html3 += '">'; //hmm
    html3 += '</div>';
    html3 += '</div>';
    html3 += '</div>';
    html3 += '</div>';

    for(var i=0;i<data;i++){
        totalHTML += html1+(i+1)+html2+(i+1)+html3;
    }

    return totalHTML;
}

function generateOptionFields(){
    var data = document.getElementById('no-question-text-input').value;
    var area = document.getElementById('gen-opt-area');

    var html = createOptionInput(data);

    area.innerHTML = html;

}


function generateOptionFields2(id1,id2){
    var data = document.getElementById(id1).value;
    var area = document.getElementById(id2);

    var html = createOptionInput(data);

    area.innerHTML = html;

}